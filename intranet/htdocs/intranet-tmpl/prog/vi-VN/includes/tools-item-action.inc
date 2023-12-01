 [% IF item_action_ignore AND num_items == 0 %]
 No items were found during staging
 <input type ="hidden" name="item_action" value="ignore">
 [% ELSE %]
 <select name="item_action" id="item_action">
 [% IF ( item_action_always_add ) %]
 <option value="always_add" selected="selected">
 [% ELSE %]
 <option value="always_add">
 [% END %] Luôn luôn thêm tài liệu</option>
 [% IF ( item_action_add_only_for_matches ) %]
 <option value="add_only_for_matches" selected="selected">
 [% ELSE %]
 <option value="add_only_for_matches">
 [% END %] Thêm tài liệu nếu tìm thấy biểu ghi phù hợp</option>
 [% IF ( item_action_add_only_for_new ) %]
 <option value="add_only_for_new" selected="selected">
 [% ELSE %]
 <option value="add_only_for_new">
 [% END %] Thêm tài liệu nếu không tìm thấy biểu ghi phù hợp</option>
 [% IF ( item_action_replace ) %]
 <option value="replace" selected="selected">
 [% ELSE %]
 <option value="replace">
 [% END %] Thay thế tài liệu hiện tại nếu tìm thấy biểu ghi phù hợp</option>
 [% IF ( item_action_ignore ) %]
 <option value="ignore" selected="selected">
 [% ELSE %]
 <option value="ignore">
 [% END %] Luôn luôn bỏ qua tài liệu</option>
 </select>
 [% END %]
