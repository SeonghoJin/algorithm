With AdsCount AS (
    Select ad.ad_id, SUM(
        case 
            when ad.action = 'Clicked' then 1
            when ad.action = 'Viewed' then 1
        else
            0
        end
    ) as total from Ads ad
    group by ad_id
), ClickCount AS (
    Select ad.ad_id, SUM(
        case 
            when ad.action = 'Clicked' then 1
        else
            0
        end
    ) as total from Ads ad
    group by ad_id
)

Select ac.ad_id, IF(ROUND((cc.total / ac.total) * 100, 2), ROUND((cc.total / ac.total) * 100, 2), 0) as ctr from AdsCount ac
left join ClickCount cc on ac.ad_id = cc.ad_id
order by ctr desc, ac.ad_id asc
